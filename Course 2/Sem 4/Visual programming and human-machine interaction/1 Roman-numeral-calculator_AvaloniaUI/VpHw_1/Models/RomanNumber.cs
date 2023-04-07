using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VpHw_1.Models
{
    public class RomanNumber : ICloneable, IComparable
    {

        private ushort _number;
        private static int[] values = new int[] { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        private static string[] roman = new string[]
            { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        //Конструктор получает представление числа n в римской записи
        public RomanNumber(ushort n)
        {
            if (n <= 0) throw new RomanNumberException($"Число {n} меньше либо равно 0");
            else this._number = n;
        }
        //Сложение римских чисел
        public static RomanNumber operator +(RomanNumber? n1, RomanNumber? n2)
        {
            if (n1 == null || n2 == null) throw new RomanNumberException("Не удалось сложить  числа!");
            int num = n1._number + n2._number;
            if (num <= 0) throw new RomanNumberException("Не удалось сложить  числа!");
            else
            {
                return new RomanNumber((ushort)num);
            }
        }
        //Вычитание римских чисел
        public static RomanNumber operator -(RomanNumber? n1, RomanNumber? n2)
        {
            if (n1 == null || n2 == null) throw new RomanNumberException("Результат вычитания меньше либо равен 0!");
            int num = n1._number - n2._number;
            if (num <= 0) throw new RomanNumberException("Результат вычитания меньше либо равен 0!");
            else
            {
                return new RomanNumber((ushort)num);
            }
        }
        //Умножение римских чисел
        public static RomanNumber operator *(RomanNumber? n1, RomanNumber? n2)
        {
            if (n1 != null && n2 != null)
            {
                int num = n1._number * n2._number;
                if (num <= 0) throw new RomanNumberException("Не удалось умножить 2 числа!");
                else
                {
                    return new RomanNumber((ushort)num);
                }
            }
            throw new RomanNumberException("Не удалось умножить 2 числа!");
        }

        //Целочисленное деление римских чисел
        public static RomanNumber operator /(RomanNumber? n1, RomanNumber? n2)
        {

            if (n1 == null || n2 == null) throw new RomanNumberException("Ошибка деления!");
            if (n2._number == 0) throw new RomanNumberException("Ошибка деления!");
            else
            {
                int num = n1._number / n2._number;
                if (num == 0) throw new RomanNumberException("Ошибка деления!");
                else
                {
                    return new RomanNumber((ushort)num);
                }
            }
        }
        //Возвращает строковое представление римского числа
        public override string ToString()
        {
            int tmp = _number;
            StringBuilder result = new StringBuilder();
            for (int i = 0; i < 13; i++)
            {
                while (tmp >= values[i])
                {
                    tmp -= (ushort)values[i];
                    result.Append(roman[i]);
                }
            }
            if (result.ToString() == "")
                throw new RomanNumberException("Перевод числа в Римские цифры невозможен");
            else
                return result.ToString();

        }

        public object Clone()
        {

            return new RomanNumber(_number);
        }

        public int CompareTo(object obj)
        {
            if (obj is RomanNumber roman)
                return _number.CompareTo(roman._number);
            else
                throw new RomanNumberException("object is not a RomanNumber");
        }

    }

}
