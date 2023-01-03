using CppInterop;
using CppInterop.Managed;
using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace SearchClient
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        TernaryTrie? trie = null;

        public MainWindow()
        {
            InitializeComponent();
        }

        List<string> stringsFromFile = new List<string>();
        private void Button_Click(object sender, RoutedEventArgs e) // load
        {
            trie = new TernaryTrie();
            OpenFileDialog openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog() == true)
            {
                foreach (var str in File.ReadLines(openFileDialog.FileName))
                {
                    stringsFromFile.Add(str);
                    trie.Add(str);
                }
                FileListView.ItemsSource = stringsFromFile;

                ulong trieSize = trie.Size();
                System.Diagnostics.Trace.WriteLine($"Read {stringsFromFile?.Count ?? 0} from file, added {trieSize} to trie");
            }
        }

        ObservableCollection<String> stringsFromSearch = new ObservableCollection<string>();
        private void Button_Click_1(object sender, RoutedEventArgs e) // search
        {
            if (!RealtimeSearchCB?.IsChecked ?? false)
            {
                SearchFor(searchQueryText.Text);
                FileListViewFiltered.ItemsSource = stringsFromSearch;
            }
        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (RealtimeSearchCB?.IsChecked ?? false)
            {
                SearchFor(searchQueryText.Text);
                FileListViewFiltered.ItemsSource = stringsFromSearch;

            }
        }

        public void SearchFor(String text)
        {
            stringsFromSearch.Clear();
            trie?.Search(text).ForEach(x => stringsFromSearch.Add(x));
        }
        
    }    
}
