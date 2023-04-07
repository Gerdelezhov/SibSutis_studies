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
    public class ExcursViewModel : ViewModelBase
    {
        ObservableCollection<CityEvent> excurs;
        public ExcursViewModel(ObservableCollection<CityEvent> events)
        {
            excurs = new ObservableCollection<CityEvent>();
            var mas = events;
            for (int i = 0; i < events.Count(); i++)
            {
                if (mas[i].Category.Contains("Экскурсии") == true || mas[i].Category.Contains("экскурсии") == true)
                {
                    if (mas[i].Description.Length > 134)
                    {
                        mas[i].Description.Remove(135);
                        mas[i].Description += "...";
                    }
                    excurs.Add(new CityEvent
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

        public ObservableCollection<CityEvent> Excurs
        {
            get => excurs;
            set
            {
                this.RaiseAndSetIfChanged(ref excurs, value);
            }
        }
    }
}
