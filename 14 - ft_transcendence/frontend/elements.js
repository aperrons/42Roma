
export let header = `<nav class="navbar navbar-expand-lg navbar-light bg-light">
<a class="navbar-brand" href="#">Navbar</a>
<button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
  <span class="navbar-toggler-icon"></span>
</button>
<div class="collapse navbar-collapse" id="navbarNav">
  <ul class="navbar-nav">
    <li class="nav-item active">
      <a class="nav-link" href="#">Home <span class="sr-only">(current)</span></a>
    <li class="nav-item">
        <button type="button" id="login-button" class="btn btn-default navbar-btn">Sign in</button>
    </li>
    <li class="nav-item">
        <button type="button" id="register-button" class="btn btn-default navbar-btn">Register</button>
    </li>
  </ul>
</div>
</nav>
<nav class="navbar navbar-dark bg-dark">
<!-- Navbar content -->
</nav>`

export let footer = `<footer class="d-flex flex-wrap justify-content-between align-items-center py-3 my-4 border-top">
    <div class="col-md-4 d-flex align-items-center">
      <a href="/" class="mb-3 me-2 mb-md-0 text-body-secondary text-decoration-none lh-1">
        <svg class="bi" width="30" height="24"><use xlink:href="#bootstrap"></use></svg>
      </a>
      <span class="mb-3 mb-md-0 text-body-secondary">© 2024 Company, Inc</span>
    </div>

    <ul class="nav col-md-4 justify-content-end list-unstyled d-flex">
      <li class="ms-3"><a class="text-body-secondary" href="#"><svg class="bi" width="24" height="24"><use xlink:href="#twitter"></use></svg></a></li>
      <li class="ms-3"><a class="text-body-secondary" href="#"><svg class="bi" width="24" height="24"><use xlink:href="#instagram"></use></svg></a></li>
      <li class="ms-3"><a class="text-body-secondary" href="#"><svg class="bi" width="24" height="24"><use xlink:href="#facebook"></use></svg></a></li>
    </ul>
</footer>`;

export let register_form = `<form id="form">
<input type="text" id="first-name" placeholder="Nome">
<input type="text" id="last-name" placeholder="Cognome">
<input type="date" id="birth-date" placeholder="Data di Nascita">
<input type="email" id="email" placeholder="Email">
<input type="text" id="new-username" placeholder="Username">
<input type="password" id="new-password" placeholder="Password">
<button type="submit" id="register-submit-button" disabled="true">Register</button>
</form>`;