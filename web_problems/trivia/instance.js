document.addEventListener("DOMContentLoaded",function(){
    let buttons = document.querySelectorAll(".yes")
    buttons.forEach(function(button){
        button.addEventListener("click",function(){
            if(button.innerText == "Athens")
            {
               button.style.backgroundColor = "green"
               document.querySelector(".e").innerText = "Correct!"
            }
            else
            {
               button.style.backgroundColor = "red"
               document.querySelector(".e").innerText = "Incorrect"
            }
   })
  })

  document.querySelector(".no").addEventListener("click",function(){
    let input = document.querySelector("input")
    if(input.value.toLowerCase() == "Mars".toLowerCase())
    {   input.style.backgroundColor = "green"
        document.querySelector(".j").innerText = "Correct!"
    }
    else
    {
        input.style.backgroundColor = "red"
        document.querySelector(".j").innerText = "Incorrect!"
    }
  })
})