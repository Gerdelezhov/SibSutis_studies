using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VpHw_1.Models
{
    public class RomanNumberExtend : RomanNumber
    {
        public static ushort ToInt(string num)
        {
            if (num == null) return 0;

            num = new string(num.Reverse().ToArray());
            ushort to_int = 0;
            for (int i = 0; i < num.Length; i++)
            {
                switch (num[i])
                {
                    case 'M':
                        to_int += 1000;
                        break;
                    case 'D':
                        to_int += 500;
                        break;
                    case 'C':
                        to_int += 100;
                        if (i > 0)
                        {
                            if (num[i - 1] == 'M' || num[i - 1] == 'D')
                            {
                                to_int -= 200;
                            }
                        }
                        break;
                    case 'L':
                        to_int += 50;
                        break;
                    case 'X':
                        to_int += 10;
                        if (i > 0)
                        {
                            if (num[i - 1] == 'C' || num[i - 1] == 'L')
                            {
                                to_int -= 20;
                            }
                        }
                        break;
                    case 'V':
                        to_int += 5;
                        break;
                    case 'I':
                        to_int += 1;
                        if (i > 0)
                        {
                            if (num[i - 1] == 'X' || num[i - 1] == 'V')
                            {
                                to_int -= 2;
                            }
                        }
                        break;
                    default:
                        break;
                }
            }
            return to_int;
        }
        public RomanNumberExtend(string num) : base(ToInt(num)) { }
    }
}
