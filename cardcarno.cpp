#include "cardcarno.h"
#include <cstdint>

//вычислисление минимальных НДФ (form = 1) или минимальных НКФ (form = 0) для 16 аргументов ФАЛ
bool CardCarno::calculate(bool form, string args)
{
	//проверка пользователя на дурака
	if (args.size() == 16 &&
			args.find('0') != string::npos &&
			args.find('1') != string::npos &&
			args.find_first_not_of("01*") == string::npos) {

		//если  результат уже есть, зачем вычислять заново?!
		if (args != mArgs || form != mForm || mFlatExps.size() == 0) {
            mArgs = args;
			mForm = form;

			//инициализации карты Крано на основании аргументов функции
			vector<vector<char>> argsCard;
			initArgsCard(args, argsCard);

			//инициализации карты покрытия областей склеивания, для карты Карно
			vector<vector<bool>> coversCard;
			initCoversCard(coversCard);			

			//нахождение областей склеивания карты Карно
			vector<vector<unsigned int>> findedCovers;
			find3RankCovers(form, argsCard, coversCard, findedCovers);
			find2RankCovers(form, argsCard, coversCard, findedCovers);
			find1RankCovers(form, argsCard, coversCard, findedCovers);
			find0RankCovers(form, argsCard, coversCard, findedCovers);

			//генерация минимальных комбинаций областей склеивания, покрывающих карту Карно
			vector<vector<vector<unsigned int>>> coversCombs;
			genCoversCombs(form, argsCard, findedCovers, coversCombs);

			//генерация логических выражений на основе областей склеивания карты Карно
			genExpressions(form, mFlatExps, mCombExps, coversCombs);
		};

		//если результат есть - хорошо, если нет - печалька(
		if (mFlatExps.size() != 0)
			return true;
		else
			return false;

    } else
		return false;
}

//получение минимальных решений в виде строки
vector<string> CardCarno::getFlatExps()
{
	return mFlatExps;
}

//получение минимальных решений в виде набора термов
vector<vector<string> > CardCarno::getCombExps()
{
	return mCombExps;
}

//проверка области склеивания: удовлетворение выбранной форме (НКФ, НДФ) и включение в области > порядка
bool CardCarno::isValidCover(bool& form, vector<unsigned int>& cover,
							 vector<vector<bool>>& coversCard,
							 vector<vector<char>>& argsCard)
{
	bool isArgExist = false;
	char arg = form ? '1' : '0';

	//проверяем область на соответствие выбранной форме (НДФ, НКФ)
	for (unsigned int i = 0; i < cover.size(); i += 2)
		if (argsCard[cover[i]][cover[i + 1]] == arg)
			isArgExist = true;
		else if (argsCard[cover[i]][cover[i + 1]] != '*')
			return false;

	//если все аргументы в области не определены - "*"
	if (!isArgExist)
		return false;

	//если в области есть минимум 1 аргумент, который ещё не покрыт
	for (unsigned int i = 0; i < cover.size(); i += 2)
		if (argsCard[cover[i]][cover[i + 1]] == arg && coversCard[cover[i]][cover[i + 1]] == false)
			return true;

	return false;
}

//проверка областей склеивания на полное покрытие карты Карно
bool CardCarno::isValidCoversComb(bool& form, vector<vector<unsigned int>> &coversComb,
								  vector<vector<char>> &argsCard)
{

	//инициализации карты покрытия областей склеивания, для карты Карно
	vector<vector<bool>> coversCard;
	initCoversCard(coversCard);

	//заполнение карты покрытия на основе областей склеивания
	fillCoversCard(0, coversComb, coversCard);

	char arg = form ? '1' : '0';
	for (unsigned int i = 0; i < argsCard.size(); i++)
		for (unsigned int j = 0; j < argsCard[i].size(); j++)
			//если не вся карта покрыта
			if (argsCard[i][j] == arg && !coversCard[i][j])
				return false;

	return true;
}

//инициализации карты покрытия областей склеивания, для карты Карно
void CardCarno::initCoversCard(vector<vector<bool> >& coversCard)
{
	coversCard = {{0, 0, 0, 0, 0},
				  {0, 0, 0, 0, 0},
				  {0, 0, 0, 0, 0},
				  {0, 0, 0, 0, 0},
				  {0, 0, 0, 0, 0}};
}

//инициализации карты Крано на основании аргументов функции
void CardCarno::initArgsCard(string& args, vector<vector<char>>& argsCard)
{
	//инициализации карты Карно с дополнительной строкой (4) и столбцом (4), для проверки областей на границах
    // argsCard = {{args[12], args[14], args[10], args[8], args[12]},
    // 			{args[13], args[15], args[11], args[9], args[13]},
    // 			{args[ 5], args[ 7], args[ 3], args[1], args[ 5]},
    // 			{args[ 4], args[ 6], args[ 2], args[0], args[ 4]},
    // 			{args[12], args[14], args[10], args[8], args[12]}};
    argsCard = {
        {args[3], args[11], args[9], args[1], args[3]},  // строка 0
        {args[7], args[15], args[13], args[5], args[7]},  // строка 1
        {args[6], args[14], args[12], args[4], args[6]},  // строка 2
        {args[2], args[10], args[8], args[0], args[2]},   // строка 3
        {args[3], args[11], args[9], args[1], args[3]}    // строка 4 (дубликат)
    };
}

//заполнение карты покрытия на основе областей склеивания
void CardCarno::fillCoversCard(int pos,
							   vector<vector<unsigned int>>& covers,
							   vector<vector<bool> >& coversCard)
{
	//отмечаем области склеивания на карте покрытия
	for (unsigned int i = pos; i < covers.size(); i++)
		for (unsigned int j = 0; j < covers[i].size(); j += 2)
			coversCard[covers[i][j]][covers[i][j + 1]] = true;

	//синхронихируем дополнительные строку и столбец (0<->4)
	for (unsigned int i = 1; i < 4; i++) {
		if (coversCard[i][0] || coversCard[i][4]) {
			coversCard[i][0] = 1;
			coversCard[i][4] = 1;
		}
		if (coversCard[0][i] || coversCard[4][i]) {
			coversCard[0][i] = 1;
			coversCard[4][i] = 1;
		}
	}

	//синхронихируем ячейки для проверки области склеивания по углам карты
	if (coversCard[0][0] || coversCard[4][4] || coversCard[0][4] || coversCard[4][0]) {
		coversCard[0][0] = 1;
		coversCard[4][4] = 1;
		coversCard[0][4] = 1;
		coversCard[4][0] = 1;
	}
}

//нахождение областей склеивания карты Карно размером 2^3 клеток
void CardCarno::find3RankCovers(bool& form,
								vector<vector<char>>& argsCard,
								vector<vector<bool>>& coversCard,
								vector<vector<unsigned int>>& findedCovers)
{
	unsigned int coversCnt = findedCovers.size();

	vector<unsigned int> cover;
	for (unsigned int i = 0; i < 4; i++) {
		//по строкам
		cover = {i, 0, i, 1, i, 2, i, 3, i + 1, 0, i + 1, 1, i + 1, 2, i + 1, 3};
		//если область подходит, то добавляем
		if (isValidCover(form, cover, coversCard, argsCard))
			findedCovers.push_back(cover);

		//по столбцам
		cover = {0, i, 1, i, 2, i, 3, i, 0, i + 1, 1, i + 1, 2, i + 1, 3, i + 1};
		//если область подходит, то добавляем
		if (isValidCover(form, cover, coversCard, argsCard))
			findedCovers.push_back(cover);
	}

	//заполняем карту порытия на основе добавленных областей
	if (coversCnt < findedCovers.size())
		fillCoversCard(coversCnt, findedCovers, coversCard);
}

//нахождение областей склеивания карты Карно размером 2^2 клеток
void CardCarno::find2RankCovers(bool& form,
								vector<vector<char>>& argsCard,
								vector<vector<bool>>& coversCard,
								vector<vector<unsigned int>>& findedCovers)
{
	unsigned int coversCnt = findedCovers.size();

	vector<unsigned int> cover;

	for (unsigned int i = 0; i < 4; i++) {
		//по строкам
		cover = {i, 0, i, 1, i, 2, i, 3};
		//если область подходит, то добавляем
		if (isValidCover(form, cover, coversCard, argsCard))
			findedCovers.push_back(cover);

		//по столбцам
		cover = {0, i, 1, i, 2, i, 3, i};
		//если область подходит, то добавляем
		if (isValidCover(form, cover, coversCard, argsCard))
			findedCovers.push_back(cover);
	}

	for (unsigned int i = 0; i < 4; i++)
		for (unsigned int j = 0; j < 4; j++) {
			//квадратная область
			cover = {i, j, i, j + 1, i + 1, j, i + 1, j + 1};
			//если подходит, то добавляем
			if (isValidCover(form, cover, coversCard, argsCard))
				findedCovers.push_back(cover);
		}

	//заполняем карту порытия на основе добавленных областей
	if (coversCnt < findedCovers.size())
		fillCoversCard(coversCnt, findedCovers, coversCard);
}

//нахождение областей склеивания карты Карно размером 2^1 клеток
void CardCarno::find1RankCovers(bool& form,
								vector<vector<char>>& argsCard,
								vector<vector<bool>>& coversCard,
								vector<vector<unsigned int>>& findedCovers)
{
	unsigned int coversCnt = findedCovers.size();

	vector<unsigned int> cover;
	for (unsigned int i = 0; i < 4; i++)
		for (unsigned int j = 0; j < 4; j++) {
			//по строкам
			cover = {i, j, i, j + 1};
			//если подходит, то добавляем
			if (isValidCover(form, cover, coversCard, argsCard))
				findedCovers.push_back(cover);

			//по столбцам
			cover = {i, j, i + 1, j};
			//если подходит, то добавляем
			if (isValidCover(form, cover, coversCard, argsCard))
				findedCovers.push_back(cover);
		}

	//заполняем карту порытия на основе добавленных областей
	if (coversCnt < findedCovers.size())
		fillCoversCard(coversCnt, findedCovers, coversCard);
}

//нахождение областей склеивания карты Карно размером 2^0 клеток
void CardCarno::find0RankCovers(bool& form,
								vector<vector<char>>& argsCard,
								vector<vector<bool>>& coversCard,
								vector<vector<unsigned int>>& findedCovers)
{
	unsigned int coversCnt = findedCovers.size();

	vector<unsigned int> cover;
	for (unsigned int i = 0; i < 4; i++)
		for (unsigned int j = 0; j < 4; j++) {
			//по клеткам (ячейкам)
			cover = {i, j};
			//если подходит, то добавляем
			if (isValidCover(form, cover, coversCard, argsCard))
				findedCovers.push_back(cover);
		}

	//заполняем карту порытия на основе добавленных областей
	if (coversCnt < findedCovers.size())
		fillCoversCard(coversCnt, findedCovers, coversCard);
}

//генерация минимальных комбинаций областей склеивания, покрывающих карту Карно
void CardCarno::genCoversCombs(bool& form, vector<vector<char>>& argsCard,
							   vector<vector<unsigned int>>& findedCovers,
							   vector<vector<vector<unsigned int>>>& coversCombs)
{
	coversCombs.clear();
	if (findedCovers.size() > 0) {

		int num, pow;
		unsigned int coversInComb = INT32_MAX;
		vector<unsigned int> cover;
		vector<vector<unsigned int>> coversComb;

		//количество возможных комбинаций = 2^(кол-во найденных областей) - 1 (пустая комбинация)
		for(int cnt = power(2, findedCovers.size()) - 1; cnt > 0; cnt--) {
			coversComb.clear();
			num = cnt;
			//добавляем комбинации на основе счета в бинарной системе 111 -> 110 -> 101 -> 100 -> ...
			for (int i = findedCovers.size() - 1; i >= 0; i--) {
				pow = power(2, i);
				if (num >= pow) {
					num -= pow;
					cover = findedCovers[i];
					coversComb.push_back(cover);
					cover.clear();
				}
			}

			//если комбинация покрывает карту Карно, то добавляем
			if (isValidCoversComb(form, coversComb, argsCard)) {
				//если кол-во областей в комбинации меньше ранее добавленных, то очищаем
				if (coversComb.size() < coversInComb) {
					coversCombs.clear();
					coversCombs.push_back(coversComb);
					coversInComb = coversComb.size();
				} else if (coversComb.size() == coversInComb)
					coversCombs.push_back(coversComb);
			};
		}
	}
}


//возведение числа в степень
int CardCarno::power(int num, unsigned int power)
{
	int result;
	result = power == 0 ? 1 : num;

	if (power > 1)
		for (; power > 1; power--)
			result *= num;

	return result;
}
