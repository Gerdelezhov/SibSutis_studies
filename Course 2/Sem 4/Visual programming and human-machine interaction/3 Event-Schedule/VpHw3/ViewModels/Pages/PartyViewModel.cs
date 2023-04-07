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
    public class PartyViewModel : ViewModelBase
    {
        ObservableCollection<CityEvent> party;
        public PartyViewModel(ObservableCollection<CityEvent> events)
        {
            party = new ObservableCollection<CityEvent>();
            var mas = events;
            for (int i = 0; i < events.Count(); i++)
            {
                if (mas[i].Category.Contains("Вечеринки") == true || mas[i].Category.Contains("вечеринки") == true)
                {
                    if (mas[i].Description.Length > 134)
                    {
                        mas[i].Description.Remove(135);
                        mas[i].Description += "...";
                    }
                    party.Add(new CityEvent
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

        public ObservableCollection<CityEvent> Party
        {
            get => party;
            set
            {
                this.RaiseAndSetIfChanged(ref party, value);
            }
        }
    }
}
