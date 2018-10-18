pageextension 50112 CustomerCardExtension extends "Customer Card"
{

    layout
    {
        // Add changes
    }

    actions
    {
        addlast("&Customer")
        {   
            action("Show Greeting")
            {
                RunObject = codeunit HelloWorld;
                RunPageOnRec = True;
                Image = CheckDuplicates;
                PromotedCategory = Category8;
                Promoted = true;
                ApplicationArea = All; 
            }
        }
    }    
}
