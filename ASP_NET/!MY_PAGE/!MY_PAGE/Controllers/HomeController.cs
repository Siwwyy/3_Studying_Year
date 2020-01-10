//using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Web;
//using System.Web.Mvc;
//using _MY_PAGE.Models;

using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Data.SqlClient;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using Microsoft.AspNet.Identity;
using _MY_PAGE.Models;

namespace _MY_PAGE.Controllers
{
    public class HomeController : Controller
    {
        //Users
        private ApplicationDbContext db = new ApplicationDbContext();

        public ActionResult Index()
        {
            return View();
        }

        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }

        public ActionResult Dodaj_Ogloszenie()
        {
            ViewBag.Message = "Add your advertisement.";

            return View();
        }

        public ActionResult Wyszukaj_Ogloszenie()
        {
            ViewBag.Message = "Find your car";

            return View();
        }

        ////Display Users
        //[HttpGet]
        public ActionResult Manage_Accounts_Admin()
        {
            ViewBag.Message = "Admin Panel";
            return View(db.Users.ToList());
        }

        [HttpPost]
        public ActionResult Delete_User(string id)
        {
            var User = db.Users.Find(id);
            db.Users.Remove(User);
            db.SaveChanges();
            return RedirectToAction("Index", "Home");
        }
    }
}