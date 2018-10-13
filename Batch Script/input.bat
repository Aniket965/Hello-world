@echo off
setlocal EnableDelayedExpansion
:::::
:: Advanced user input in batch [using xcopy]
:::::
:: Returns by echoing result.
:: Fetching using for /f from main
:::::
set "prompt="
:: the input prompt
set "symbol="
:: the symbol that displays instead
set "length="
:: the max length of the input
set "allowed="
:: allowed characters ("a b c A B C")
set "invalid="
:: invalid characters ("b c d B C D")
:: allowed characters will override invalid
:::::

:: parse flags dict
:flags
if not "%~1" == "" (
    set "%~1"
    shift
    goto flags
)

:: Fetch needed characters
for /f %%A in ('copy /Z "%comspec%" nul') do set "CR=%%A"
for /f %%A in ('"prompt $H&for %%B in (1) do rem"') do set "BS=%%A"
:: start of program
if defined symbol set "symbol=%symbol:~0,1%"
set "input=."
<NUL set /p "=.!BS! !BS!!prompt!" >CON
:input
set "key="
for /f "delims=" %%A in ('xcopy /w "%comspec%" "%comspec%" 2^>nul') do if not defined key set "key=%%A"
set "key=!key:~-1!"
if !key! equ !BS! (
    if NOT "!input!" == "." (
        set "input=!input:~0,-1!"
        <NUL set /p "=!BS! !BS!" >CON
    )
) else if !key! equ !CR! (
    echo+ >CON
    echo+!input:~1!
    exit /B 0
) else (
    if defined length (
        if "!input:~-%length%!" == "!input!" (call)
    ) else (
        (call)
    )
) || (
    if defined allowed (
        for %%A IN (!allowed!) DO if %%A equ !key! (
            set "input=!input!!key!"
            if defined symbol (
                <NUL set /p "=!symbol!" >CON
            ) else (
                <NUL set /p "=.!BS!!key!" >CON
            )
        )
    ) else (
        for %%A IN (!invalid!) DO if %%A equ !key! goto input
        set "input=!input!!key!"
        if defined symbol (
            <NUL set /p "=!symbol!" >CON
        ) else (
            <NUL set /p "=.!BS! !BS!!key!" >CON
        )
    )
)
goto input
