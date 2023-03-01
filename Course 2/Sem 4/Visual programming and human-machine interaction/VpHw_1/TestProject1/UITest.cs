using Avalonia.Controls;
using Avalonia.Controls.ApplicationLifetimes;
using Avalonia.Controls.Shapes;
using Avalonia.Media;
using Avalonia.VisualTree;
using VpHw_1.Views;
using System;
using System.IO;


namespace UITestsForRomanNumbersCalculator {
    public class UITest {
        IClassicDesktopStyleApplicationLifetime app = AvaloniaApp.GetApp();
        MainWindow mainWindow = AvaloniaApp.GetMainWindow();
        Button button_I, button_V, button_X, button_L, button_C, button_D, button_M;
        Button button_Plus, button_Sub, button_Mul, button_Div;
        Button button_CE, button_result;
        TextBlock textblock_main;
        public UITest() {
            var buttons = mainWindow.GetVisualDescendants().OfType<Button>();

            button_I = buttons.First(b => b.Name == "I");
            button_V = buttons.First(b => b.Name == "V");
            button_X = buttons.First(b => b.Name == "X");
            button_L = buttons.First(b => b.Name == "L");
            button_C = buttons.First(b => b.Name == "C");
            button_D = buttons.First(b => b.Name == "D");
            button_M = buttons.First(b => b.Name == "M");

            button_Plus = buttons.First(b => b.Name == "Add");
            button_Sub = buttons.First(b => b.Name == "Sub");
            button_Mul = buttons.First(b => b.Name == "Mul");
            button_Div = buttons.First(b => b.Name == "Div");

            button_CE = buttons.First(b => b.Name == "CE");
            button_result = buttons.First(b => b.Name == "result");

            var text_blocks = mainWindow.GetVisualDescendants().OfType<TextBlock>();

            textblock_main = text_blocks.First(b => b.Name == "textBlockMain");
        }

        internal void Press_I() => button_I.Command.Execute(button_I.CommandParameter);
        internal void Press_V() => button_V.Command.Execute(button_V.CommandParameter);
        internal void Press_X() => button_X.Command.Execute(button_X.CommandParameter);
        internal void Press_L() => button_L.Command.Execute(button_L.CommandParameter);
        internal void Press_C() => button_C.Command.Execute(button_C.CommandParameter);
        internal void Press_D() => button_D.Command.Execute(button_D.CommandParameter);
        internal void Press_M() => button_M.Command.Execute(button_M.CommandParameter);
        internal void Press_Plus() => button_Plus.Command.Execute(button_Plus.CommandParameter);
        internal void Press_Sub() => button_Sub.Command.Execute(button_Sub.CommandParameter);
        internal void Press_Mul() => button_Mul.Command.Execute(button_Mul.CommandParameter);
        internal void Press_Div() => button_Div.Command.Execute(button_Div.CommandParameter);
        internal void Press_CE() => button_CE.Command.Execute(button_CE.CommandParameter);
        internal void Press_Result() => button_result.Command.Execute(button_result.CommandParameter);

        public string TextMain() { return textblock_main.Text; }

        [Fact]
        public async Task Test1() {
            Press_CE();
            await Task.Delay(10);
            Assert.Equal("", TextMain());
        }
        [Fact]
        public async Task Test2() {
            Press_CE();
            await Task.Delay(10);
            Press_I();
            Press_V();
            Press_I();
            await Task.Delay(10);
            Assert.Equal("IVI", TextMain());
        }

        [Fact]
        public async Task Test3() {
            Press_CE();
            await Task.Delay(10);
            Press_CE();
            Press_I();
            Press_Mul();
            Press_I();
            Press_I();
            await Task.Delay(10);
            Assert.Equal("II", TextMain());
        }
        [Fact]
        public async Task Test5() {
            Press_CE();
            await Task.Delay(10);
            Press_M();
            Press_D();
            Press_C();
            Press_L();
            Press_Sub();
            Press_X();
            Press_I();
            Press_V();
            Press_Plus();
            Press_C();
            Press_C();
            Press_V();
            Press_I();
            Press_I();
            await Task.Delay(10);
            Assert.Equal("CCVII", TextMain());
            Press_Div();
            Press_L();
            Press_V();
            Press_Mul();
            Press_L();
            Press_X();
            await Task.Delay(10);
            Assert.Equal("LX", TextMain());
            Press_Div();
            Press_M();
            Press_M();
            Press_M();
            await Task.Delay(10);
            Assert.Equal("MMM", TextMain());
        }
        [Fact]
        public async Task Test6() {
            Press_CE();
            await Task.Delay(10);
            Press_M();
            Press_M();
            Press_M();
            Press_C();
            Press_M();
            Press_X();
            Press_C();
            Press_I();
            Press_X();
            await Task.Delay(10);
            Assert.Equal("MMMCMXCIX", TextMain());
            Press_Plus();
            Press_I();
            Press_Result();
            await Task.Delay(10);
            Assert.Equal("MMMM", TextMain());
        }
        [Fact]
        public async Task Test7() {
            Press_CE();
            await Task.Delay(10);
            Press_M();
            Press_Sub();
            Press_M();
            Press_Plus();
            await Task.Delay(10);
            Assert.Equal("ERROR", TextMain());
            Press_CE();
            Press_C();
            Press_Mul();
            Press_X();
            Press_I();
            Press_X();
            Press_I();
            await Task.Delay(10);
            Assert.Equal("XIXI", TextMain());
        }
    }
}