package;

import openfl.display.Sprite;

/**
 * ...
 * @author AVL
 */
class Main extends Sprite
{
	public function new()
	{
		super();
		
		var img = new openfl.text.TextField();
		img.text = "Hello World!";
		img.textColor = 0xffffff;
		addChild(img);
	}
}
