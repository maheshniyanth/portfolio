const navSlide = () =>{
    const mobile = document.querySelector('.mobile');
    const Catagories = document.querySelector('.Catagories');
    const nav = document.querySelectorAll('.Catagories li');

    mobile.addEventListener('click', () => {
        Catagories.classList.toggle('nav-active');

        nav.forEach((link, index) => {
            link.style.animation = 'navLinkFade 0.5s ease forwars ${index/7 +0.3}s';
        })
    })
}
const app = ()=>{
    navSlide();
}
app();