class HelloHUD extends HudBase;
 
simulated function DrawHudPassC (Canvas C)
{
 C.SetPos( 0.50*C.ClipX , 0.50*C.ClipY);
 C.DrawText("Hello World!");
}
 
defaultproperties
{
}
