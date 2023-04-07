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
    public class CultureViewModel:ViewModelBase
    {
        private ObservableCollection<CityEvent> culture;

        public CultureViewModel(ObservableCollection<CityEvent> events)
        {
            culture = new ObservableCollection<CityEvent>();
            var mas = events;
            for(int i = 0; i < events.Count(); i++)
            {
                if (mas[i].Category.Contains("Культура")==true || mas[i].Category.Contains("культура")==true)
                {
                    if (mas[i].Description.Length > 134)
                    {
                        mas[i].Description.Remove(135);
                        mas[i].Description += "...";
                    }
                    culture.Add(new CityEvent
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

        public ObservableCollection<CityEvent> Culture
        {
            get => culture;
            set
            {
                this.RaiseAndSetIfChanged(ref culture, value);
            }
        }
    }
}
