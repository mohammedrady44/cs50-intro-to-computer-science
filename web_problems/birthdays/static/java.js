document.addEventListener("DOMContentLoaded",function(){
   let buttons = document.querySelectorAll(".ab")
   buttons.forEach(function(button){
    button.addEventListener("click",function(){
        if(button.innerText == "Add Birthday")
        {
            document.querySelector(".sp").value = "insert"
        }
        else if(button.innerText == "Update Birthday")
        {
            document.querySelector(".sp").value = "update"
            document.querySelector(".bl").style.display = "block"
            if (document.querySelector("#n_3").value)
            {
                document.querySelector("form").submit()
            }
        }
        else
        {
            document.querySelector(".sp").value = "delete"
        }
    })

   })
})