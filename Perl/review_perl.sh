#!/bin/bash
# review_perl.sh requires perlcritic
# testing with prove requires perl-Test-Simple
PERLSOURCE=$1

if test -z "$PERLSOURCE"
then
    echo "$0 PERLSOURCE"
    exit 2
fi

### http://confluence.jetbrains.net/display/TCD65/Build+Script+Intermyaction+with+TeamCity
mydebug="$DEBUG"   # set by env.DEBUG  variable in TeamCity, values: mydebug / <empty>
myaction="$ACTION" # set by env.ACTION variable in TeamCity, values: clone / <anything_else>

print_text()
{
    local myState=$(echo $1 | cut -d: -f1)
    if [[ $myState =~ "mydebug" ]]
    then
        if [ ! -z "$mydebug" ]
        then
            echo "$*"
        fi
    else
        echo "$*"
        if   [[ "$myState" =~ "warning" ]]
        then
            echo "##teamcity[message text='warning reported' status='WARNING']"
        elif [[ "$myState" =~ "error" ]]
        then
            echo "##teamcity[message text='error reported' errorDetails='${*}' status='ERROR']"
            echo "##teamcity[testFailed name='${current_test}' message='error present in logs' details='${*}']"
        elif [[ "$myState" =~ "fatal" ]]
        then
            echo "##teamcity[message text='fatal error reported' errorDetails='tests will now stop' status='ERROR']"
            exit 1
        fi
        ### TODO add more/less mydebugging info if needed, or teamcity block/reporting
    fi
}

print_all_parameters()
{
    print_text "##teamcity[blockOpened name='showRunParameters']"

    print_text "##teamcity[blockClosed name='showRunParameters']"
}


tc_started_testsuite()
{
    print_text "##teamcity[testSuiteStarted name='Perl::Critic']"
}

tc_finished_testsuite()
{
    print_text "##teamcity[testSuiteFinished name='Perl::Critic']"
}

tc_start_test()
{
    local mytest=$1
    print_text "##teamcity[testStarted name='${mytest}']"
    current_test=${mytest}
}

tc_end_test()
{
    local mytest=$1
    print_text "##teamcity[testFinished name='${mytest}']"
    current_test=""
}

publish_artifacts()
{
    print_text "##teamcity[blockOpened name='publishingArtifacts']"

    print_text "##teamcity[blockClosed name='publishingArtifacts']"
    kdestroy
}


my_tests()
{
    tc_start_test "syntax_check"
    perl -c "${PERLSOURCE}" || exit $!
    tc_end_test   "syntax_check"

    tc_start_test "gentle_style_check"
    perlcritic -gentle "${PERLSOURCE}" || exit 5
    tc_end_test   "gentle_style_check"

    tc_start_test "stern_style_check"
    perlcritic -stern "${PERLSOURCE}" || exit 4
    tc_end_test   "stern_style_check"

    tc_start_test "harsh_style_check"
    perlcritic -harsh "${PERLSOURCE}" || exit 3
    tc_end_test   "harsh_style_check"

    tc_start_test "cruel_style_check"
    perlcritic -cruel "${PERLSOURCE}" || exit 2
    tc_end_test   "cruel_style_check"

    tc_start_test "brutal_style_check"
    perlcritic -brutal "${PERLSOURCE}" || exit 1
    tc_end_test   "brutal_style_check"

    tc_start_test "perl_prove"
    prove
    tc_end_test   "perl_prove"


}


echo "$TEAMCITY_PROJECT_NAME"
tc_started_testsuite
my_tests "$1"
tc_finished_testsuite

exit 0
