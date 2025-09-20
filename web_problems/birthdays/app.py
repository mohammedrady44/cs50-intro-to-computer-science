from flask import Flask,request,render_template,redirect
import mysql.connector

app = Flask(__name__)
ins = mysql.connector.connect(user= "root",password = "7500763",host="127.0.0.1",database = "original")
ready = ins.cursor()


@app.route("/",methods = ["GET","POSt"])
def home():
    
    if request.method == "POST":
        name,month,day = request.form.get("name"),request.form.get("month"),request.form.get("day")
        n_name,n_month,n_day = request.form.get("new_name"),request.form.get("new_month"),request.form.get("new_day")
        if name and month and day:
            if request.form.get("action") == "insert":
                ready.execute("insert into birthdays(name,month,day) values(%s,%s,%s)",(name,month,day))
            elif request.form.get("action") == "delete":
                ready.execute("delete from birthdays where name = %s and month = %s and day = %s",(name,month,day))    
            else:
                if n_name and n_month and n_day:
                    sql_query = "update birthdays set name = %s,month = %s,day = %s where name = %s and month = %s and day = %s"    
                    ready.execute(sql_query,(n_name,n_month,n_day,name,month,day))
            
            ins.commit()    
        return redirect("/")  
       

    else:
        ready.execute("select name,month,day from birthdays")
        return render_template("index.html",data = ready)



    
