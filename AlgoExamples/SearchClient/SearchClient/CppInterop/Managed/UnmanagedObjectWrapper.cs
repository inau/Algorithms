using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CppDLL.Managed
{
    abstract class UnmanagedObjectWrapper : IDisposable
    {
        private bool disposedValue;

        protected abstract void AllocatePointer();
        protected abstract void DeAllocatePointer();

        protected virtual void Dispose(bool disposing)
        {
            if (!disposedValue)
            {
                if (disposing)
                {
                    // TODO: dispose managed state (managed objects)
                }

                // TODO: free unmanaged resources (unmanaged objects) and override finalizer
                // TODO: set large fields to null

                DeAllocatePointer();
                
                disposedValue = true;
            }
        }
        protected UnmanagedObjectWrapper()
        {
            AllocatePointer();
        }

        // // TODO: override finalizer only if 'Dispose(bool disposing)' has code to free unmanaged resources
        ~UnmanagedObjectWrapper()
        {
            // Do not change this code. Put cleanup code in 'Dispose(bool disposing)' method
            Dispose(disposing: false);
        }

        public void Dispose()
        {
            // Do not change this code. Put cleanup code in 'Dispose(bool disposing)' method
            Dispose(disposing: true);
            GC.SuppressFinalize(this);
        }
    }
}
