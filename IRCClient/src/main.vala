/* main.vala
 *
 * Copyright (C) 2011  Ventzislav Dimitrov
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *  
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *  
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Author:
 * 	Ventzislav Dimitrov <dimitrovventzislav@googlemail.com>
 */
using Sqlite;
using GLib;

namespace IRC
{
	public class Main : Object 
	{
		public Main () {}

		public void run () 
		{
			Message msg = new Message("ventzo","Hi!","channel","server", new DateTime.now_local());
			SQLiteDB.Insert(msg);
			SQLiteDB.ShowLog("ventzo");
			
			MyServer server = new MyServer();
			
			server.Connect();
			stdout.printf ("Server ist verbunden!\n");
			
		}

		static int main (string[] args)
		{
			var main = new Main ();		
			
			main.run ();

			return 0;
		}
	}
}
