using Sqlite;
namespace IRC
{
	public class SQLiteDB : Object
	{
		public SQLiteDB()
		{
			
		}
				
		public static Database DataBase;			
		
		private const string _path = Module.build_path (Environment.get_variable("PWD"),"MyLogData.db");
		
		public static void CreateDB()
		{
			int result = Database.open(_path, out DataBase);
			
			string createLog = "CREATE TABLE MyLogData (Username TEXT, Message TEXT NULL, Channel TEXT, Server TEXT, Timestamp INTEGER)";	
			
			if(result == Sqlite.OK)
			{
				DataBase.exec(createLog,null,null);
			}			
		}
		
		
		public static void Insert(Message message)
		{
			if(DataBase == null)
			{
				stdout.printf ("Datenbank wird erstellt!\n");
				CreateDB();
			}
		
			string commandText = "INSERT INTO MyLogData (Username, Message, Channel, Server, Timestamp) VALUES (@1, @2, @3, @4, @5)";
			
			Statement statement;
			
			DataBase.prepare_v2(commandText, -1, out statement);
			
			statement.bind_text(1, message.Username);
			statement.bind_text(2, message.MessageContent);
			statement.bind_text(3, message.Channel);
			statement.bind_text(4, message.Server);
			statement.bind_int64(5, message.UnixTime);
			statement.step();
		}
		
		public static void ShowLog(string username)
		{
			stdout.printf ("Datenbank wird ausgelesen!\n");
		
			Database.open(_path, out DataBase);
		
			string commandText = "SELECT * FROM MyLogData WHERE Username = @1 ORDER BY Timestamp DESC LIMIT 10";
						
			Statement statement;
			
			DataBase.prepare_v2(commandText, -1, out statement);		
			
			statement.bind_text(1, username);
			
			int result = statement.step();
			
			List<Message> results = new List<Message>();
					
			while (result == Sqlite.ROW)
			{
				var Username = statement.column_text(0);
				var MessageContent = statement.column_text(1);
				var Channel = statement.column_text(2);
				var Server = statement.column_text(3);
				var FromUnixTime = new DateTime.from_unix_local(statement.column_text(4).to_int64());
				var msg = new Message(Username,MessageContent,Channel,Server,FromUnixTime);
				results.append(msg);
				result = statement.step();	
			}
			
			
			foreach(Message r in results)
			{
				stdout.printf("%s\n", r.MessageContent);
			}
			
		}
	}	
		
}
	


