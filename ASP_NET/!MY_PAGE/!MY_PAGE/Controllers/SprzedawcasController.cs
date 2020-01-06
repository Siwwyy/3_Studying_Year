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
    public class SprzedawcasController : Controller
    {
        private ApplicationDbContext db = new ApplicationDbContext();

        // GET: Sprzedawcas
        public ActionResult Index()
        {
            return View(db.Seller.ToList());
        }

        // GET: Sprzedawcas/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Sprzedawca sprzedawca = db.Seller.Find(id);
            if (sprzedawca == null)
            {
                return HttpNotFound();
            }
            return View(sprzedawca);
        }

        // GET: Sprzedawcas/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Sprzedawcas/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "ID,Imie,Nazwiska,Pesel")] Sprzedawca sprzedawca)
        {
            if (ModelState.IsValid)
            {
                db.Seller.Add(sprzedawca);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(sprzedawca);
        }

        // GET: Sprzedawcas/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Sprzedawca sprzedawca = db.Seller.Find(id);
            if (sprzedawca == null)
            {
                return HttpNotFound();
            }
            return View(sprzedawca);
        }

        // POST: Sprzedawcas/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "ID,Imie,Nazwiska,Pesel")] Sprzedawca sprzedawca)
        {
            if (ModelState.IsValid)
            {
                db.Entry(sprzedawca).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(sprzedawca);
        }

        // GET: Sprzedawcas/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Sprzedawca sprzedawca = db.Seller.Find(id);
            if (sprzedawca == null)
            {
                return HttpNotFound();
            }
            return View(sprzedawca);
        }

        // POST: Sprzedawcas/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Sprzedawca sprzedawca = db.Seller.Find(id);
            db.Seller.Remove(sprzedawca);
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
