using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CppInterop
{
    public class CppDLL
    {
        const string DLLName = "AlgorithmDLL.dll";
        public static class Trie
        {
            [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
            static public extern IntPtr CreateTrieObject();
        
            [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
            static public extern void DisposeTrie(IntPtr pClassNameObject);

            [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
            static public extern uint Size(IntPtr pClassNameObject);

            [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
            static public extern void Add(IntPtr pClassNameObject, string text);

            [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
            static public extern void Search(IntPtr pClassNameObject, string text, IntPtr resultContainer);

            [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
            static public extern IntPtr ToDotString(IntPtr pClassNameObject);
        }

        public static class Result
        {
            [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
            static public extern IntPtr CreateResultObject();
        
            [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
            static public extern void DisposeResult(IntPtr pClassNameObject);
        
            [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
            static public extern uint getResultSize(IntPtr pClassNameObject);
        
            [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
            static public extern IntPtr getResultElement(IntPtr pClassNameObject, uint index);
        
            [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
            static public extern IntPtr ItemGetText(IntPtr pClassNameObject);
        }
    }
}
