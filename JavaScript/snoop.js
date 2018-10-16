//this script when added to parent DOM (webpage) will return/ print the css path of
//any element relative to parent DOM. Including the elements inside multiple nested
// iframes. The iframes need to be from same domain ofcource.

//author - Kshitij Mhatre

document.onload = dig2(document, "");

document.addEventListener("click", ev => console.log(fullPath(ev.target)));

function dig2(innerDoc, prevbase) {
  iframes = innerDoc.querySelectorAll("iframe");
  for (let i = 0; i < iframes.length; i++) {
    console.log(iframes[i]);
    base = prevbase + " > " + fullPath(iframes[i]);

    var innerDoc =
      iframes[i].contentDocument || iframes[i].contentWindow.document;
    innerDoc.onload = dig2(innerDoc, base);
    innerDoc.addEventListener("click", ev => {
      console.log(ev.target);
      console.log(prevbase + " > " + fullPath(ev.target));
    });
  }
}

function fullPath(el) {
  var names = [];
  while (el.parentNode) {
    if (el.id) {
      names.unshift("#" + el.id);
      break;
    } else {
      if (el == el.ownerDocument.documentElement) names.unshift(el.tagName);
      else {
        for (
          var c = 1, e = el;
          e.previousElementSibling;
          e = e.previousElementSibling, c++
        );
        names.unshift(el.tagName + ":nth-child(" + c + ")");
      }
      el = el.parentNode;
    }
  }
  return names.join(" > ");
}
