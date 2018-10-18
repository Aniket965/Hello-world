package;

import World;

class Main {
	// run with haxe -x Main.hx
	static public function main():Void {
		var w = new World(20, 20);

		w.set(3, 3, true);
		w.set(4, 4, true);
		w.set(4, 5, true);
		w.set(3, 5, true);
		w.set(2, 5, true);

		trace("Hello world");

		while (true) {
			Sys.command("clear");

			printWorld(w);

			Sys.sleep(0.500);
			w.step();
		}
	}

	static public function printWorld(w:World) {
		trace(Math.random());
		for (row in w.m) {
			trace(row.map(function(v) {
					return v ? "x" : " ";
				}).join(""));
		}
	}
}
