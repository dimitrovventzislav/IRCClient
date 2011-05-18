using GLib;

namespace IRC
{
	public class MyServer : Object
	{		
		public string RealName { get; set; }
		public string Nickname { get; set; }
		public string Username { get; set; }
		private SocketClient _socketClient;
		public string Host { get; set; }
		public uint16 Port { get; set; }		
		private uint _sourceID = 0;
		public InetAddress Address { get; set; }		
		private Source _source = null;
		public InetSocketAddress SocketAddress { get; set; }		
		private SocketConnection _socketConnection;		
		private DataInputStream _inputStream;		
		private IOChannel _channel;
		private Cancellable _cancellable;
		private IOCondition _conditions;
		
		public signal void DataReceived (string buffer, size_t len);
		public signal void Disconnected ();

		
		
		public MyServer()
		{
			this.RealName = "Ventzislav Dimitrov";
			this.Nickname = "DeeveN";
			this.Username = "DeeveN";
			this.Host = "Hamburg.DE.EU.undernet.org";
			this.Port = 6667; 
			this._cancellable = new Cancellable();
		}
		
		public async new void Connect()
		{
			stdout.printf ("connect fired\n");
			Resolver res = Resolver.get_default();			
			List<InetAddress> results = res.lookup_by_name(this.Host,_cancellable);
			if(results != null)
			{
				this.Address =(InetAddress) results.nth_data(0);
				this.SocketAddress = new InetSocketAddress(Address, Port);							
			}
		
			try
			{
				this._socketClient = new SocketClient();
				
				this._socketClient.set_protocol(SocketProtocol.TCP);
				
				this._socketConnection =_socketClient.connect(SocketAddress);
				
				stdout.printf ("socketConnection ist verbunden\n");			
				
				Monitoring();
			}
			catch
			{
				stdout.printf ("fehler\n");			
			}
		}
		
		public void Monitoring()
		{
			this._cancellable = null;
			this._socketConnection.get_socket().set_blocking(false);
			this._inputStream = new DataInputStream(_socketConnection.input_stream);
			stdout.printf ("inputStream ist verbunden\n");			
			this._conditions = IOCondition.IN | IOCondition.HUP | IOCondition.ERR | IOCondition.NVAL;
			this._channel = new IOChannel.unix_new(_socketConnection.get_socket().get_fd());
			this._channel.init();
			
			this._sourceID = _channel.add_watch(this._conditions, this.SocketCallback);
			stdout.printf ("channel watche\n");
		}
		
		private bool SocketCallback (IOChannel source, IOCondition condition)
		{
			bool res = true;

			switch (condition) 
			{
				case IOCondition.IN:
					size_t length = -1;
					
                                   var message = new StringBuilder ();
                                   
					while (length != 0) 
					{
						try 
						{
							string buffer = _inputStream.read_line (out length, null);
							if (buffer != null) 
							{
								message.append_printf ("%s\n", buffer);
							}
						}
						catch
						{
							stdout.printf ("Err\n");
						}
					}

                                        if (message.len > 0) 
                                        {
                                                this.on_data_received (message.str, message.len);
                                        } 
                                        else 
                                        {                                                
                                                this.Disconnect ();
                                        }
					break;
			}
			return res;
		}
		
		public void Disconnect ()
		{
			Cleanup ();
			on_disconnected ();
		}
		protected virtual void on_disconnected ()
		{
			Disconnected ();
		}
		private void Cleanup ()
		{
			try {
				
				Source.remove_by_user_data (this);

				if (_sourceID != 0) {
					Source.remove (_sourceID);
					_sourceID = 0;
				}
			
				if (_source != null) {
					_source.destroy ();
					_source = null;
				}

				if (_socketConnection != null) {
					_inputStream = null;
					_channel = null;
					_socketConnection.close (null);
					_socketConnection = null;
				}
				if (_socketClient != null) {
					_socketClient = null;
				}
			} 
			catch (Error err) 
			{
				warning ("error cleanup: %s", err.message);
			}
		}
		protected virtual void on_data_received (string buffer, size_t len)
		{
			//data_received (buffer, len);
		}


	}
}
