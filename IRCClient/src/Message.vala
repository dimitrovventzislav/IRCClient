using GLib;

namespace IRC
{
	public class Message
	{
		public Message(string username,string message, string channel, string server, DateTime time)
		{
			Username = username; 
			Time = time;
			Channel = channel;
			Server = server;
			MessageContent = message;
		}		
		
		public string Username { get; set; }
		
		public DateTime Time { get; set; }
		
		public string Channel { get; set; }
		
		public string Server { get; set; }
		
		public int64 UnixTime 
		{
			get
			{
				return Time.to_unix();
			}
		}

		public string MessageContent { get; set; }
	}
}
