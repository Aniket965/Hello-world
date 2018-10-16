*** Settings ***
Library    SeleniumLibrary
Suite Setup    Open google.com by google chrome
Suite Teardown   End Browser
Test Teardown    Back to google.com
Test Template    Search google by keyword
*** Variables ***
${GOOGLE URL}    https://google.com
${WEB BROWSER}    googlechrome

*** Keywords ***
Search google by keyword
    [Arguments]    ${KEYWORD}
    Enter text in the search box    ${KEYWORD}
    Press the search button

Open google.com by google chrome
    Open Browser    ${GOOGLE URL}    ${WEB BROWSER}
    Wait Until Element Is Visible    id=lst-ib

Enter text in the search box
    [Arguments]    ${KEYWORD}
    Input Text    id=lst-ib    ${KEYWORD}

Press the search button
    Press Key    name=btnK    13
    Click Button    name=btnK

Back to google.com
    Go To    ${GOOGLE URL}

End Browser
    Close Browser
    
*** Testcases ***
search-helloworld    hello world
search-hacktoberfest    Hacktoberfest-2018/Hello-world