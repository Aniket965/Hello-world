$Colors = [enum]::GetValues([System.ConsoleColor]) | Where-Object {$_ -ne 'Black'}
$Message = "Hello World!"
$Ticker = 0
$ColorTicker = 0

do {
    $Message.ToCharArray() | ForEach-Object {
        if ($ColorTicker -gt ($Colors.Count - 1)) {
            $ColorTicker = 0
        }

        Write-Host $_ -ForegroundColor $Colors[$ColorTicker] -NoNewline

        $ColorTicker++

        Start-Sleep -Milliseconds 1
    }

    Write-Host "`r" -NoNewline

    $Ticker++
}
while ($Ticker -lt 25)