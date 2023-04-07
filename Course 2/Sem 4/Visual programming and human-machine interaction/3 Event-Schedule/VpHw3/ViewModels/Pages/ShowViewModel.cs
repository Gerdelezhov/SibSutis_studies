using VpHw3.Models;
using ReactiveUI;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VpHw3.ViewModels.Pages
{
    public class ShowViewModel : ViewModelBase
    {
        ObservableCollection<CityEvent> show;
        public ShowViewModel(ObservableCollection<CityEvent> events)
        {
            show = new ObservableCollection<CityEvent>();
            var mas = events;
            for (int i = 0; i < events.Count(); i++)
            {
                if (mas[i].Category.Contains("Шоу") == true || mas[i].Category.Contains("шоу") == true)
                {
                    if (mas[i].Description.Length > 134)
                    {
                        mas[i].Description.Remove(135);
                        mas[i].Description += "...";
                    }
                    show.Add(new CityEvent
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

        public ObservableCollection<CityEvent> Show
        {
            get => show;
            set
            {
                this.RaiseAndSetIfChanged(ref show, value);
            }
        }
    }
}
