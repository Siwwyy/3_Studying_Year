using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using _MY_PAGE.Models;

namespace _MY_PAGE.Controllers
{
    public class Kraj_PochodzeniaController : Controller
    {
        private ApplicationDbContext db = new ApplicationDbContext();

        // GET: Kraj_Pochodzenia
        public ActionResult Index()
        {
            return View(db.Country.ToList());
        }

        // GET: Kraj_Pochodzenia/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Kraj_Pochodzenia kraj_Pochodzenia = db.Country.Find(id);
            if (kraj_Pochodzenia == null)
            {
                return HttpNotFound();
            }
            return View(kraj_Pochodzenia);
        }

        // GET: Kraj_Pochodzenia/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Kraj_Pochodzenia/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "ID,Nazwa_Kraj_Pochodzenia")] Kraj_Pochodzenia kraj_Pochodzenia)
        {
            if (ModelState.IsValid)
            {
                db.Country.Add(kraj_Pochodzenia);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(kraj_Pochodzenia);
        }

        // GET: Kraj_Pochodzenia/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Kraj_Pochodzenia kraj_Pochodzenia = db.Country.Find(id);
            if (kraj_Pochodzenia == null)
            {
                return HttpNotFound();
            }
            return View(kraj_Pochodzenia);
        }

        // POST: Kraj_Pochodzenia/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "ID,Nazwa_Kraj_Pochodzenia")] Kraj_Pochodzenia kraj_Pochodzenia)
        {
            if (ModelState.IsValid)
            {
                db.Entry(kraj_Pochodzenia).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(kraj_Pochodzenia);
        }

        // GET: Kraj_Pochodzenia/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Kraj_Pochodzenia kraj_Pochodzenia = db.Country.Find(id);
            if (kraj_Pochodzenia == null)
            {
                return HttpNotFound();
            }
            return View(kraj_Pochodzenia);
        }

        // POST: Kraj_Pochodzenia/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Kraj_Pochodzenia kraj_Pochodzenia = db.Country.Find(id);
            db.Country.Remove(kraj_Pochodzenia);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
