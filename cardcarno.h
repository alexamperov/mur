//	Comments in Russian, with UTF-8 encoding! ;)
/*
	Модуль минимизации функий алгебры логики (ФАЛ) методом минимизирующих карт Карно
	Автор: Буриченко Михаил Сергеевич (burichenko.m.s@ya.ru)
	2017г.
*/

#ifndef CARDCARNO_H
#define CARDCARNO_H

#include <string>
#include <vector>

using namespace std;

class CardCarno
{
public:
	CardCarno() {}

	//вычислисление минимальных НДФ (form = 1) или минимальных НКФ (form = 0) для 16 аргументов ФАЛ
	bool calculate(bool form, string args);

	//получение минимальных решений в виде строки
	vector<string> getFlatExps();

	//получение минимальных решений в виде набора термов
	vector<vector<string>> getCombExps();

protected:
	//проверка области склеивания: удовлетворение выбранной форме (НКФ, НДФ) и включение в области > порядка
	bool isValidCover(bool& form, vector<unsigned int>& cover,
					  vector<vector<bool>>& coversCard,
					  vector<vector<char>>& argsCard);

	//проверка областей склеивания на полное покрытие карты Карно
	bool isValidCoversComb(bool& form, vector<vector<unsigned int>>& coversComb,
						   vector<vector<char>>& argsCard);

	//инициализации карты покрытия областей склеивания, для карты Карно
	void initCoversCard(vector<vector<bool>>& coversCard);

	//инициализации карты Крано на основании аргументов функции
	void initArgsCard(string& args, vector<vector<char>>& argsCard);

	//заполнение карты покрытия на основе областей склеивания
	void fillCoversCard(int pos, vector<vector<unsigned int>>& covers, vector<vector<bool>>& coversCard);

	//нахождение областей склеивания карты Карно размером 2^3 клеток
	void find3RankCovers(bool& form, vector<vector<char>>& argsCard,
						 vector<vector<bool>>& coversCard, vector<vector<unsigned int>>& findedCovers);

	//нахождение областей склеивания карты Карно размером 2^2 клеток
	void find2RankCovers(bool& form, vector<vector<char>>& argsCard,
						 vector<vector<bool>>& coversCard, vector<vector<unsigned int>>& findedCovers);

	//нахождение областей склеивания карты Карно размером 2^1 клеток
	void find1RankCovers(bool& form, vector<vector<char>>& argsCard,
						 vector<vector<bool>>& coversCard, vector<vector<unsigned int>>& findedCovers);

	//нахождение областей склеивания карты Карно размером 2^0 клеток
	void find0RankCovers(bool& form, vector<vector<char>>& argsCard,
						 vector<vector<bool>>& coversCard, vector<vector<unsigned int>>& findedCovers);

	//генерация минимальных комбинаций областей склеивания, покрывающих карту Карно
	void genCoversCombs(bool& form, vector<vector<char>>& argsCard,
						vector<vector<unsigned int>>& findedCovers,
						vector<vector<vector<unsigned int>>>& coversCombs);

	//генерация логических выражений на основе областей склеивания карты Карно
	void genExpressions(bool& form, vector<string>& flatExps, vector<vector<string>>& combExps,
						vector<vector<vector<unsigned int>>>& coversCombs);

	//возведение числа в степень
	int power(int num, unsigned int power);

private:
	bool mForm;
	string mArgs;
	vector<string> mFlatExps;
	vector<vector<string>> mCombExps;
};

#endif
