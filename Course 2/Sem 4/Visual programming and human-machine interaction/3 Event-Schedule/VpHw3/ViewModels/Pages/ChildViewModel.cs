using VpHw3.Models;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ReactiveUI;

namespace VpHw3.ViewModels.Pages
{
    public class ChildViewModel : ViewModelBase
    {
        private ObservableCollection<CityEvent> child;
        public ChildViewModel(ObservableCollection<CityEvent> events)
        {
            child = new ObservableCollection<CityEvent>();
            var mas = events;
            for (int i = 0; i < events.Count(); i++)
            {
                if (mas[i].Category.Contains("Для детей") == true || mas[i].Category.Contains("для детей") == true)
                {
                    if (mas[i].Description.Length > 134)
                    {
                        mas[i].Description.Remove(135);
                        mas[i].Description += "...";
                    }
                    child.Add(new CityEvent
                    {
                        Header = mas[i].Header,
                        Description = mas[i].Description,
                        Image = mas[i].Image,
                        Date = mas[i].Date,
                        Category = mas[i].Category,
                        Price = mas[i].Price
                    });
                }
            }
        }

        public ObservableCollection<CityEvent> Child
        {
            get => child;
            set
            {
                this.RaiseAndSetIfChanged(ref child, value);
            }
        }
    }
}
