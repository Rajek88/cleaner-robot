// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getDatabase } from "firebase/database";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyBB29Bzt39YAZpaNhvXTJywGIzw7_fWaeg",
  authDomain: "stage-cleaner.firebaseapp.com",
  databaseURL: "https://stage-cleaner-default-rtdb.firebaseio.com",
  projectId: "stage-cleaner",
  storageBucket: "stage-cleaner.appspot.com",
  messagingSenderId: "663764826512",
  appId: "1:663764826512:web:f729976cade210e24a1b15",
};

// Initialize Firebase
export const app = initializeApp(firebaseConfig);
export const database = getDatabase(app);

// import urllib, json

// url = "http://maps.googleapis.com/maps/api/geocode/json?address=googleplex&sensor=false"

// response = urllib.urlopen(url)

// data = json.loads(response.read())

// print data
