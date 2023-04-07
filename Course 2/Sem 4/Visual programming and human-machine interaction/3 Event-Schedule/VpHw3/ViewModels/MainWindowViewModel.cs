using VpHw3.Models;
using VpHw3.ViewModels.Pages;
using VpHw3.Views.Pages;
using ReactiveUI;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Reactive;
using System.Text;
using System.Xml.Serialization;

namespace VpHw3.ViewModels
{
    public class MainWindowViewModel : ViewModelBase
    {
        private ObservableCollection<ViewModelBase> vmbaseCollection;
        private ObservableCollection<CityEvent> events;

        public MainWindowViewModel()
        {
            events = new ObservableCollection<CityEvent>();
            XmlSerializer xs = new XmlSerializer(typeof(ObservableCollection<CityEvent>));
            using (StreamReader rd = new StreamReader(@"..\..\..\events.xml"))
            {
                events = xs.Deserialize(rd) as ObservableCollection<CityEvent>;
            }


            vmbaseCollection = new ObservableCollection<ViewModelBase>();
            vmbaseCollection.Add(new ChildViewModel(events));
            vmbaseCollection.Add(new SportViewModel(events));
            vmbaseCollection.Add(new CultureViewModel(events));
            vmbaseCollection.Add(new ExcursViewModel(events));
            vmbaseCollection.Add(new LifeViewModel(events));
            vmbaseCollection.Add(new PartyViewModel(events));
            vmbaseCollection.Add(new EducationViewModel(events));
            vmbaseCollection.Add(new OnlineViewModel(events));
            vmbaseCollection.Add(new ShowViewModel(events));
        }


        public object Child { get => vmbaseCollection[0]; }
        public object Sport { get => vmbaseCollection[1]; }
        public object Culture { get => vmbaseCollection[2]; }
        public object Excurs { get => vmbaseCollection[3]; }
        public object Life { get => vmbaseCollection[4]; }
        public object Party { get => vmbaseCollection[5]; }
        public object Education { get => vmbaseCollection[6]; }
        public object Online { get => vmbaseCollection[7]; }
        public object Show { get => vmbaseCollection[8]; }

    }
}
