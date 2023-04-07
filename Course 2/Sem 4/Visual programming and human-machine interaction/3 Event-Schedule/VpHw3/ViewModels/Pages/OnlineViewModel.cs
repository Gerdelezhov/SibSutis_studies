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
    public class OnlineViewModel : ViewModelBase
    {
        ObservableCollection<CityEvent> online;
        public OnlineViewModel(ObservableCollection<CityEvent> events)
        {
            online = new ObservableCollection<CityEvent>();
            var mas = events;
            for (int i = 0; i < events.Count(); i++)
            {
                if (mas[i].Category.Contains("Онлайн") == true || mas[i].Category.Contains("онлайн") == true)
                {
                    if (mas[i].Description.Length > 134)
                    {
                        mas[i].Description.Remove(135);
                        mas[i].Description += "...";
                    }
                    online.Add(new CityEvent
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

        public ObservableCollection<CityEvent> Online
        {
            get => online;
            set
            {
                this.RaiseAndSetIfChanged(ref online, value);
            }
        }
    }
}
