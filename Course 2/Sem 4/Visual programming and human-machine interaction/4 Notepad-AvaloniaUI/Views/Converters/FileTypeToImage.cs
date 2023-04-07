using Avalonia;
using Avalonia.Controls;
using Avalonia.Data.Converters;
using Avalonia.Media.Imaging;
using System;
using System.Globalization;
using VpHw_4.Models;
using static VpHw_4.Models.FileTypes;

namespace VpHw_4.Views.Converters
{
    internal class FileTypeToImage : IValueConverter
    {
        public object? Convert(
            object? value,
            Type targetType,
            object? parameter,
            CultureInfo culture
        )
        {
            if (value == null)
                return null;
            if (value is FileTypes @f_t)
            {
                string icon = @f_t switch
                {
                    SysDrive => "sys_drive",
                    Drive => "drive",
                    BackFolder => "back_folder",
                    Folder => "folder",
                    FILE => "file",
                    _ => ""
                };
                var app = Application.Current;
                if (app == null)
                    return null;
                var ress = app.Resources;
                var img = (Image?)ress[icon];
                if (img == null)
                    return null;
                return (Bitmap?)img.Source;
            }
            throw new NotSupportedException();
        }

        public object? ConvertBack(
            object? value,
            Type targetType,
            object? parameter,
            CultureInfo culture
        )
        {
            throw new NotImplementedException();
        }
    }
}
