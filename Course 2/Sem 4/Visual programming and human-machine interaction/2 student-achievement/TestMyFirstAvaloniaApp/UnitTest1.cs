using Avalonia.Controls;
using Avalonia.Controls.ApplicationLifetimes;
using Avalonia.VisualTree;
using ControlPeriod;
using ControlPeriod.Views;

namespace TestMyFirstAvaloniaApp
{
    public class UnitTest1
    {
        IClassicDesktopStyleApplicationLifetime app = AvaloniaApp.GetApp();
        MainWindow mainWindow = AvaloniaApp.GetMainWindow();
        Button button_Add, button_Delete;
        TextBlock TextBlock_0, TextBlock_1, TextBlock_2, TextBlock_Mark1, TextBlock_Mark2, TextBlock_Mark3, TextBlock_Average;
        TextBox TextBox_BoxMark1, TextBox_BoxMark2, TextBox_BoxMark3;
        public UnitTest1()
        {
            var buttons = mainWindow.GetVisualDescendants().OfType<Button>();

            button_Add = buttons.First(b => b.Name == "Add");
            button_Delete = buttons.First(b => b.Name == "Delete");


            var text_blocks = mainWindow.GetVisualDescendants().OfType<TextBlock>();
            // три нижних блока со следними оценками
            TextBlock_0 = text_blocks.First(b => b.Name == "TextBlock_0");
            TextBlock_1 = text_blocks.First(b => b.Name == "TextBlock_1");
            TextBlock_2 = text_blocks.First(b => b.Name == "TextBlock_2");
            // с инд. оценками
            //TextBlock_Mark1 = text_blocks.First(b => b.Name == "blMark1");
            /*TextBlock_Mark2 = text_blocks.First(b => b.Name == "blMark2");
            TextBlock_Mark3 = text_blocks.First(b => b.Name == "blMark3");*/
            // инд. среднее
            //TextBlock_Average = text_blocks.First(b => b.Name == "blockAverage");

            var text_box = mainWindow.GetVisualDescendants().OfType<TextBox>();
            // три нижних блока со следними оценками
            /*TextBox_BoxMark1 = text_box.First(b => b.Name == "BoxMark1");
            TextBox_BoxMark2 = text_box.First(b => b.Name == "BoxMark2");
            TextBox_BoxMark3 = text_box.First(b => b.Name == "BoxMark3");*/
        }
        
        internal void Press_Add() => button_Add.Command.Execute(button_Add.CommandParameter);
        internal void Press_Delete() => button_Delete.Command.Execute(button_Delete.CommandParameter);

        public string strBlock_0() { return TextBlock_0.Text; }
        public string strBlock_1() { return TextBlock_1.Text; }
        public string strBlock_2() { return TextBlock_2.Text; }
        /*public string strMark1() { return TextBlock_Mark1.Text; }
        public string strMark2() { return TextBlock_Mark2.Text; }
        public string strMark3() { return TextBlock_Mark3.Text; }
        public string strAverage() { return TextBlock_Average.Text; }*/


        [Fact]
        public void Test1()
        {
            Press_Add();
            //TextBox_BoxMark1.Text = "1";
            Assert.Equal("0", strBlock_0());
            Assert.Equal("0", strBlock_1());
            Assert.Equal("0", strBlock_2());
        }
    }
}