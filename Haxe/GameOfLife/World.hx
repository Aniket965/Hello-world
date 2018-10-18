package;

class World {
	public var m:Array<Array<Bool>>;
	public var height:Int;
	public var width:Int;

	public function new(height:Int = 10, width:Int = 10) {
		this.height = height;
		this.width = width;
		this.m = new Array();
		for (y in 0...height) {
			m[y] = new Array();
			for (x in 0...width)
				m[y][x] = false;
		}
	}

	public function set(x, y, v) {
		m[y][x] = v;
	}

	public function get(x, y) {
		if (x < 0 || y < 0 || x >= width || y >= height)
			return false;
		else
			return m[y][x];
	}

	public function step() {
		var next = new Array();
		for (y in 0...height) {
			next[y] = new Array();
			for (x in 0...width) {
				var neighbours:Int = getNeighbours(x, y);
				if (m[y][x]) {
					next[y][x] = neighbours == 2 || neighbours == 3;
				} else {
					next[y][x] = neighbours == 3;
				}
			}
		}

		this.m = next;
	}

	public function getNeighbours(x, y) {
		return [
			get(x - 1, y - 1),
			get(x - 1, y),
			get(x - 1, y + 1),
			get(x, y - 1),
			get(x, y + 1),
			get(x + 1, y - 1),
			get(x + 1, y),
			get(x + 1, y + 1)
		].filter(function(e) return e).length;
	}
}
