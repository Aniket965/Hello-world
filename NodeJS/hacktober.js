const str = 'HacktoberFest2k18!';

for (i = 0; i < str.length; i++) {
    for (j = 0; j <= i; j++)
        process.stdout.write(str[j]);
    process.stdout.write('\n');
}
