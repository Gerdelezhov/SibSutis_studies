using Avalonia.Controls;
using System.ComponentModel;

namespace RGR.Views.Shapes {
    public partial class HS: GateBase, IGate, INotifyPropertyChanged {
        public override int TypeId => 4;

        public override UserControl GetSelf() => this;
        protected override IGate GetSelfI => this;
        protected override int[][] Sides => new int[][] {
            System.Array.Empty<int>(),
            new int[] { 0, 0 },
            new int[] { 1, 1 },
            System.Array.Empty<int>()
        };

        protected override void Init() => InitializeComponent();

        /*
         * Мозги
         */

        public void Brain(ref bool[] ins, ref bool[] outs) {
            bool a = ins[0], b = ins[1];
            outs[0] = a ^ b;
            outs[1] = a && b;
        }
    }
}
