function downloadFile(filename) {
  let link = document.createElement('a');
  link.href = filename; // Assumes files are in the root folder
  link.download = filename;
  document.body.appendChild(link);
  link.click();
  document.body.removeChild(link);
}