  entity hello_world is
  end;
   
  architecture hello_world of hello_world is
  begin
    stimulus : process
    begin
      assert false report "Hello World By XLR"
      severity note;
    wait;
    end process stimulus;
  end hello_world;
