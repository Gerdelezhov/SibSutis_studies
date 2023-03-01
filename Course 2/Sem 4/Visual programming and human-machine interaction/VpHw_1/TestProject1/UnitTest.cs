using VpHw_1.Models;

namespace UITestsForRomanNumbersCalculator
{
    public class UnitTest
    {
        [Fact]
        //[Fact(Skip = "skip")]
        public void Test()
        {
            Assert.False(false, "AAA");
        }
        [Fact]
        public void Add()
        {
            //arrange
            var romanNumber = new RomanNumber(8);
            var romanNumber1 = new RomanNumber(1);
            var romanNumber2 = new RomanNumber(120);
            var expected1 = new RomanNumber(9);
            var expected2 = new RomanNumber(128);
            //act
            RomanNumber actual1 = romanNumber + romanNumber1;
            RomanNumber actual2 = romanNumber + romanNumber2;
            //assert
            Assert.Equal(expected1.ToString(), actual1.ToString());
            Assert.Equal(expected2.ToString(), actual2.ToString());

        }
        [Fact]
        public void Mul()
        {
            //arrange
            var romanNumber = new RomanNumber(8);
            var romanNumber1 = new RomanNumber(6);
            var romanNumber2 = new RomanNumber(12);
            var expected1 = new RomanNumber(48);
            var expected2 = new RomanNumber(96);
            //act
            RomanNumber actual1 = romanNumber * romanNumber1;
            RomanNumber actual2 = romanNumber * romanNumber2;
            //assert
            Assert.Equal(expected1.ToString(), actual1.ToString());
            Assert.Equal(expected2.ToString(), actual2.ToString());
        }

        [Fact]
        public void ToStringTest()
        {
            //arrange
            RomanNumber romanNumber = new RomanNumber(1002);
            string expected = "MII";
            //act
            string actual = romanNumber.ToString();
            //assert
            Assert.Equal(expected, actual);
        }

        [Fact]
        public void CloneTest()
        {
            //arrange
            RomanNumber romanNumber = new RomanNumber(5);
            RomanNumber expected = new RomanNumber(5);
            //act
            RomanNumber clone = (RomanNumber)romanNumber.Clone();
            //assert
            Assert.Equal(expected.ToString(), clone.ToString());
            Assert.NotSame(expected, clone);
        }


        [Fact]
        public void CompareToTest()
        {
            //arrange
            RomanNumber romanNumber = new RomanNumber(10);
            RomanNumber romanNumber1 = new RomanNumber(10);
            const int expected = 0;
            //act
            int actual = romanNumber.CompareTo(romanNumber1);
            //assert
            Assert.Equal(expected, actual);
        }
    }
}