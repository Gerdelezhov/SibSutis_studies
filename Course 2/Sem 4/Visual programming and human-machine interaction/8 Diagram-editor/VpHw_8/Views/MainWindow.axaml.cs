using Avalonia.Controls;
using VpHw_8.ViewModels;

namespace VpHw_8.Views {
    public partial class MainWindow: Window {
        public MainWindow() {
            InitializeComponent();
            DataContext = new MainWindowViewModel(this);
        }
    }
}