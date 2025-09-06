-- Enable clipboard support
vim.opt.clipboard:append("unnamedplus")

-- Enable syntax highlighting
vim.cmd("syntax on")

-- Enable true color support
vim.opt.termguicolors = true

-- Apply the habamax colorscheme
vim.cmd("colorscheme habamax")

vim.opt.number = true
vim.api.nvim_set_keymap(
  "i",
  "<Tab>",
  'pumvisible() ? "\\<C-y>" : "\\<Tab>"',
  { noremap = true, expr = true }
)
