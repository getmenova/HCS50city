@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "GET":
        return render_template("register.html")
    elif request.method == "POST":
        if not request.form.get("name") or not request.form.get("dorm"):
            return render_template("failure.html")
        db.execute("INSERT INTO registrants (name, dorm) VALUES(:name, :dorm)",
                   name=request.form.get("name"), dorm=request.form.get("dorm"))
        return render_template("success.html")


#If the request was made with the GET method, then our application returns the template for the registration form in register.html.
#If the request was made with the POST method, and both name and dorm were provided in the form, then we INSERT that data into our database with db.execute. Otherwise, we return failure.html.