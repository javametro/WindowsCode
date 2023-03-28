using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading.Tasks;

namespace CheckListeningPort
{
    class Program
    {
        static void Main(string[] args)
        {
            int portNum = 28262;
            IPGlobalProperties ipGlobalProperties = IPGlobalProperties.GetIPGlobalProperties();
            IPEndPoint[] tcpConnInfoArray = ipGlobalProperties.GetActiveTcpListeners();
            foreach(IPEndPoint endpoint in tcpConnInfoArray)
            {
                if(endpoint.Port == portNum)
                {
                    Console.WriteLine($"port {portNum} is listending");
                }
            }
        }
    }
}
