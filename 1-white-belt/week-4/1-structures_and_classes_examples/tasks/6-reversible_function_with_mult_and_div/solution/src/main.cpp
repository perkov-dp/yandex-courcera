#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

/*
 * Добавьте в класс Function из задачи «Обратимая функция» 
 * обработку умножения ('*') и деления ('/'). 
 * Гарантируется отсутствие элементарных операций умножения и деления на 0.
 * 
 * Вывод
 * 72
 * 5
 */

struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

/*
 * Для одной функции Function создается в-р объектов vector <FunctionPart> parts,
 * к-рый представляет из себя части ф-ции (операцию и операнд).
 * Для того, чтобы что-то поменять в в-ции, н/поменять операцию и 
 * в зависимости от нее результат
 */
class FunctionPart
{
public:
    //  принимает символ операции и операнд
    FunctionPart(char new_operation, double new_value) {
      operation = new_operation;
      value = new_value;
    }
    //  применение операции к введенному числу
    //  не меняет текущую операцию
    double Apply(double source_value) const {
        if (operation == '+') {
            //  к source_value прибавить операнд этой операции
            return source_value + value;
        } else if (operation == '-') {  // operation == '-'
            //  из source_value вычесть операнд этой операции
            return source_value - value;
        }
        else if (operation == '*') {
        //  к source_value прибавить операнд этой операции
            return source_value * value;
        } else if (operation == '/') {  // operation == '-'
            //  из source_value вычесть операнд этой операции
            return source_value / value;
        }
    }
    //  обращение ф-ции и элементарных операций
    void Invert() {
        if (operation == '+') {
            operation = '-';
        } else if (operation == '-') {  // operation == '-'
            operation = '+';
        }
        else if (operation == '*') {
            operation = '/';
        }
        else if (operation == '/') {
            operation = '*';
        }
    }    
private:
    char operation;
    double value;
};

//  констр-р не нужен, достаточно констр-ра по умолчанию
class Function
{
public:
    //  добавляет очередную часть в нашу ф-ю
    //  принимает символ операции и операнд
    void AddPart (const char& operation, double value)
    {
        parts.push_back({operation, value});
    }
    /*
     * Чтобы применить ф-цию к конкретному знач-ю, н/ последовательно к этому знач-ю 
     * применить все элементарные операции.
     */
    double Apply(double value) const
    {
        //   не меняем эти операции => циклимся по константной ссылке
        for (const FunctionPart& part : parts) {
            value = part.Apply(value);
        }
        return value;
    }
    /*
     * Чтобы инвертироваьб ф-ю, н/инвертировать каждую элементарную операцию.
     * Также нужно все операции перевернуть (1 становится последней, последняя первой и т.д.)
     */
    void Invert ()
    {
        //  к-дую часть меняем
        for (FunctionPart& part : parts) {
            part.Invert();
        }
        reverse(begin(parts), end(parts));       
    }
private:
    //  набор элементарных операций
    vector <FunctionPart> parts;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}


int main(int argc, char** argv) {
    Image image = {10, 2, 6};
    Params params = {4, 2, 6};
    cout << ComputeImageWeight(params, image) << endl;
    cout << ComputeQualityByWeight(params, image, 52) << endl;

    return 0;
}

