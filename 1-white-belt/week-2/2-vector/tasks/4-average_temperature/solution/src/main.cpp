#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

/*
 * Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней. 
 * Найдите номера дней (в нумерации с нуля) со значением температуры 
 * выше среднего арифметического за все N дней.

 * Гарантируется, что среднее арифметическое значений температуры является целым числом.

 * Формат ввода
 * Вводится число N, затем N неотрицательных целых чисел — значения 
 * температуры в 0-й, 1-й, ... (N?1)-й день.

 * Формат вывода
 * Первое число K — количество дней, значение температуры в которых 
 * выше среднего арифметического. Затем K целых чисел — номера этих дней.

 * Пример

 * Ввод
 * 5
 * 7 6 3 0 9

 * Вывод
 * 3
 * 0 1 4
 */

void PrintVector(const vector <int>& vec)
{
    /*
     * сделали auto для того, чтобы при изменении типа выводимого в-ра 
     * менять его т/в параметрах ф-и
     * Также передаем в-р по константной ссылке. По ссылке быстрее перебираются эл-ты, 
     * а const защищает в-р от изменения.
     */
    for (auto i : vec)
        cout << i << " ";
}

//  на вход подается в-р температур и считается СО в-ра температур
int average (const vector<int>& inputData)
{
    int sum = 0;
    int average = 0;
    
    for (auto i : inputData)
        sum += i;
    
    average = sum / inputData.size();
    
    return average;
}

//  формируем новый в-р значений > средней температуры
vector <int> setVectorBiggerAverage (int vecSize, const vector <int>& inpVec)
{
    vector <int> outputVec;
    int i = 0;
    int averageVector = average (inpVec);
    
    while (i < vecSize)
    {
        if (inpVec[i] > averageVector)
            outputVec.push_back(i);
        ++i;
    }
    
    return outputVec;
}

int main(int argc, char** argv) {
    int n = 0;
    cin >> n;
    vector <int> temperatures(n);
    vector <int> retVec;
    int i = 0;
    for (int& temperature : temperatures)
        cin >> temperature;
    
    //  в-р температур > СО изначального в-ра
    retVec = setVectorBiggerAverage (temperatures.size(), temperatures);
    cout << retVec.size() << endl;
    PrintVector(retVec);

    return 0;
}

