function validateForm() {
    var x=document.forms["reg_form"]["user"].value;
   if (x==null || x=="") {
        alert("user-id cannot be empty");
        return false;
    }
   
if(x.length<5 || x.length>12) {
   alert("user-id is invalid");
        return false;
}

 x=document.forms["reg_form"]["password"].value;
   if (x==null || x=="") {
        alert("password must be filled out");
        return false;
    }
   
if(x.length<5 || x.length>12) {
   alert("password is invalid");
        return false;
}

 x=document.forms["reg_form"]["name"].value;
   if (x==null || x=="") {
        alert("Name must be filled out");
        return false;
    }
    for(i=0;i<x.length;i++)
    {
     if(x.charAt(i)>='0' && x.charAt(i)<='9')
       { alert("Name must be Alphabetic only");
        return false;        
        }
    }

 x=document.forms["reg_form"]["address"].value;
   if (x==null || x=="") {
        alert("Address must be filled out");
        return false;
    }


var y=document.forms["reg_form"]["zipcode"].value;
   if (y==null || y=="") {
        alert("Zipcpde must be filled out");
        return false;
    }
    if (isNaN(y)){
         alert("Zipcpde must be Numerical Only");
        return false;
     }
     
x = document.forms["reg_form"]["email"].value;
    var atpos = x.indexOf("@");
    var dotpos = x.lastIndexOf(".");
    if (atpos< 1 || dotpos<atpos+2 || dotpos+2>=x.length) {
        alert("Not a valid e-mail address");
        return false;
    }


}