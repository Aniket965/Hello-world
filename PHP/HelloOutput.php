<?php

$handle = fopen('php://output', 'w');
fwrite($handle, 'Hello world');
fclose($handle);
