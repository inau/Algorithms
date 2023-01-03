using CppDLL.Managed;
using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace CppInterop.Managed
{
    class TernaryTrie : UnmanagedObjectWrapper
    {
        protected IntPtr _triePointer = IntPtr.Zero;
        protected IntPtr _resultPointer = IntPtr.Zero;

        protected override void AllocatePointer()
        {
            _triePointer = CppDLL.Trie.CreateTrieObject();
            _resultPointer = CppDLL.Result.CreateResultObject();
        }

        protected override void DeAllocatePointer()
        {
            CppDLL.Trie.DisposeTrie(_triePointer);
            CppDLL.Result.DisposeResult(_resultPointer);
        }

        public ulong Size()
        {
            return CppDLL.Trie.Size(_triePointer);
        }
        
        public void Add(string str)
        {
            CppDLL.Trie.Add(_triePointer, str);
        }

        public List<string> Search(string str)
        {
            List<string> result = new List<string>();

            CppDLL.Trie.Search(_triePointer, str, _resultPointer);

            uint cnt = CppDLL.Result.getResultSize(_resultPointer);
            for (uint i = 0; i < cnt; ++i)
            {
                IntPtr element = CppDLL.Result.getResultElement(_resultPointer, i);
                IntPtr txt = CppDLL.Result.ItemGetText(element);
                string tmp = Marshal.PtrToStringUni(txt);
                result.Add(tmp);
            }

            return result;
        }

        public string to_dot_string()
        {
            return "";
        }
    }
}
