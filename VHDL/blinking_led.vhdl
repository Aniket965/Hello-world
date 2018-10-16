LIBRARY ieee;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY ledblinker IS
	PORT (
		i_CLK: IN STD_LOGIC;
		o_LED1: OUT STD_LOGIC
	);
END ENTITY;

ARCHITECTURE bhv OF ledblinker IS
	SIGNAL clk1cnt: INTEGER RANGE 0 TO 250000000 := 0;
	SIGNAL ledout: STD_LOGIC := '0';
	
	SIGNAL oscint: STD_LOGIC;
	SIGNAL stdbyint: STD_LOGIC := '0';
	SIGNAL stdbysed: STD_LOGIC;
BEGIN

	PROCESS(i_CLK)
	BEGIN
		IF rising_edge(i_CLK) THEN
			-- input takt should be 133 MHz (T = 1 / f ~= 7,519 ns)
			-- led should blink with 1 Hz
			-- Counter has to reach 0,5 s / 7,519 ns = 66.498.204,5 
			IF clk1cnt < 66498205 THEN
				clk1cnt <= clk1cnt + 1;
			ELSE
				clk1cnt <= 0;
				ledout <= not ledout;
			END IF;
		END IF;
	END PROCESS;

	o_LED1 <= ledout;

END ARCHITECTURE;
