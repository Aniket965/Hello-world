def istermcount(a, b):
    count = 0
    string = ""
    for i,j in zip(a,b):
        if i != j:
            count += 1
            string += "-"
        else:
            string += i
    if count == 1:
        return [True, string]   
    return [False, string]



def bin_to_dec(binary):
    binary = str(binary)
    decimal = 0
    for digit in binary:
        decimal= decimal*2 + int(digit)
    return (decimal)
    

def list_combine(l1, l2):     # this function is used in step2
    return l1[:-1] + l2[:-1] + [False]


def is_full(struct):
    if(struct):
        return True
    return False
    
def remove_dontcare(vals,dont_care):
    vals = [x for x in vals if x not in dont_care]
    return vals
    
def remove_terms(to_remove,orig_dict):
    for key,value in orig_dict.items():
        new_vals = [x for x in value if x not in to_remove]
        orig_dict[key] = new_vals

def count_elemi(remkey, orig_dict):
    num = 0
    list_rem = orig_dict[remkey]
    
    for i in list_rem:
        for key, value in orig_dict.items():
            new_vals = [x for x in value if x not in list_rem]
            num_removed = len(value) - len(new_vals)
            num+=num_removed
    return num
    
def is_empty(un_used):
    for key,value in un_used.items():
        if value:
            return False
    return True
    
def answerify(answer):
    init = 97
    final_terms = ""
    for i in range(len(answer)):
        if(i!=0):
            final_terms+= " + "
        term = ""
        for j in range(len(answer[i])):
            if answer[i][j]=='0':
                term+=chr(init+j)+"'"
            elif answer[i][j]=='1':
                term+=chr(init+j)
        final_terms+=term
    return final_terms

#Take user input
user_input_min_terms = list(map(int, input("Enter Min Terms(Space Seperated): ").split())) 
user_input_dont_care = list(map(int, input("Enter Dont Care Terms(Space Seperated): ").split())) 

#To store binary values
min_terms_bin = []
dont_care_bin = []

#Convert to binary and store iun min_terms_bin
for i in user_input_min_terms:
    min_terms_bin.append(bin(i))
for i in user_input_dont_care:
    dont_care_bin.append(bin(i))

#Find the length of max number
max_num = max(min_terms_bin+dont_care_bin)
max_num_len = len(str(max_num))-2

#Add trailing zeroes based on the max number
min_terms_bin = [x[2:].zfill(max_num_len) for x in min_terms_bin]
dont_care_bin = [x[2:].zfill(max_num_len) for x in dont_care_bin]

#Convert numbers to decimal
dont_care_dec = user_input_dont_care
min_terms_dec = user_input_min_terms





dict_terms = {}

all_terms_bin = min_terms_bin + dont_care_bin

for i in all_terms_bin:
    dict_terms[i.count("1")] = []
for i in all_terms_bin:
    dict_terms[i.count("1")].append(i)

list_terms = []


for key,values in dict_terms.items():
    list_terms.append(values)

final_work_list = []

for _ in list_terms:
    final_work_list.append({})

count_previous = 0       
for i in range(len(list_terms)):
    for j in range(len(list_terms[i])):
        final_work_list[i][list_terms[i][j]] = [bin_to_dec(list_terms[i][j]), False]
        count_previous += 1




list_dict_compare = []

tbl1 = final_work_list



#tbl1 is created step 1 completed








#     --------- Step 2 starts here ---------

final_list_step = []

count_tick = 0

cur_step = 0

all_steps = [tbl1]

un_used = {}

while True:
    count_current = 0
    count_false = 0
    final_list_step = []
    for i in range(len(all_steps[cur_step])-1):
        temp_dict = {}
        for key1, value1 in all_steps[cur_step][i].items():
            for key2, value2 in all_steps[cur_step][i+1].items():
                termcount = istermcount(key1, key2)
                if termcount[0]:
                    all_steps[cur_step][i][key1][-1] = True
                    all_steps[cur_step][i+1][key2][-1] = True
                    temp_dict[termcount[1]] = list_combine(value1, value2)
                    count_current += 1
        if is_full(temp_dict):
            final_list_step.append(temp_dict)
    all_steps.append(final_list_step)
    
    #print(all_steps[cur_step])
    
    for i in all_steps[cur_step]:
        for key, values in i.items():
            if values[-1] == False:
                insert_list = remove_dontcare(values[:-1],dont_care_dec)
                un_used[key] = insert_list
                count_false += 1

    
    if count_false == count_previous:
        break
    
    count_previous = count_current
    cur_step += 1





#Step 1 - Mark the essential prime implicants and remove them
temp_dict = {}
final_answer = []
for key, value in un_used.items():
    for i in value:
        temp_dict[i] = 0

for key, value in un_used.items():
    for i in value:
        temp_dict[i] += 1

essential_imps = []

for key,value in temp_dict.items():
    if value==1:
        essential_imps.append(key)


for i in essential_imps:
    for key, value in un_used.items():
        if i in value:
            cur_essen = key
            cur_minterms = value
            final_answer.append(cur_essen)
            remove_terms(cur_minterms,un_used)
# STEP 1 END


while not is_empty(un_used):
    max_num = 0
    max_key = ""
    for key, value in un_used.items():
        cur_value = count_elemi(key, un_used)
        if max_num < cur_value:
            max_num = cur_value
            max_key = key
    final_answer.append(max_key)
    remove_terms(un_used[max_key], un_used)

print(answerify(final_answer))
